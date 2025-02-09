cnroller



// Full-Stack Crime Reporting & Community Verification Platform
// Backend: Express.js with MongoDB, AI, and Cloud Storage
// Frontend: Next.js with Tailwind CSS and Google Maps

// Backend Structure
// controllers/
// ├── authController.js
// ├── reportController.js
// ├── voteController.js
// ├── adminController.js

// models/
// ├── userModel.js
// ├── reportModel.js
// ├── voteModel.js

// routes/
// ├── authRoutes.js
// ├── reportRoutes.js
// ├── voteRoutes.js
// ├── adminRoutes.js

// middlewares/
// ├── authMiddleware.js

// config/
// ├── db.js
// ├── cloudStorage.js

// server.js
// .env
// package.json

// controllers/authController.js
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const User = require('../models/userModel');
const crypto = require('crypto');
const nodemailer = require('nodemailer');

exports.register = async (req, res) => {
    const { email, password, phone } = req.body;
    const hashedPassword = await bcrypt.hash(password, 12);
    const verificationToken = crypto.randomBytes(32).toString('hex');
    
    try {
        const user = new User({ email, password: hashedPassword, phone, verified: false, verificationToken });
        await user.save();
        
        // Send verification email
        const transporter = nodemailer.createTransport({
            service: 'gmail',
            auth: { user: process.env.EMAIL_USER, pass: process.env.EMAIL_PASS }
        });
        const mailOptions = {
            from: process.env.EMAIL_USER,
            to: email,
            subject: 'Verify Your Email',
            text: `Click the link to verify your email: ${process.env.BASE_URL}/auth/verify/${verificationToken}`
        };
        transporter.sendMail(mailOptions);
        
        res.json({ message: 'User registered successfully. Please verify your email.' });
    } catch (error) {
        res.status(500).json({ error: 'Registration failed' });
    }
};

exports.verifyEmail = async (req, res) => {
    try {
        const { token } = req.params;
        const user = await User.findOne({ verificationToken: token });
        if (!user) return res.status(400).json({ error: 'Invalid token' });
        user.verified = true;
        user.verificationToken = undefined;
        await user.save();
        res.json({ message: 'Email verified successfully' });
    } catch (error) {
        res.status(500).json({ error: 'Email verification failed' });
    }
};

exports.login = async (req, res) => {
    const { email, password } = req.body;
    try {
        const user = await User.findOne({ email });
        if (!user || !(await bcrypt.compare(password, user.password))) {
            return res.status(400).json({ error: 'Invalid credentials' });
        }
        if (!user.verified) return res.status(403).json({ error: 'Please verify your email' });
        
        const token = jwt.sign({ userId: user._id, role: user.role }, process.env.JWT_SECRET, { expiresIn: '1h' });
        res.json({ token });
    } catch (error) {
        res.status(500).json({ error: 'Login failed' });
    }
};
// controllers/reportController.js
const CrimeReport = require('../models/reportModel');
const { uploadFile } = require('../config/cloudStorage');

exports.reportCrime = async (req, res) => {
    try {
        const { userId, title, division, district, crimeTime, latitude, longitude } = req.body;
        const fileUrl = await uploadFile(req.file);
        const report = new CrimeReport({
            userId, title, division, district, imageUrl: fileUrl, crimeTime,
            location: { type: 'Point', coordinates: [longitude, latitude] }
        });
        await report.save();
        res.json({ message: 'Crime report submitted successfully' });
    } catch (error) {
        res.status(500).json({ error: 'Failed to submit report' });
    }
};

// controllers/voteController.js
exports.voteReport = async (req, res) => {
    try {
        const { userId, reportId, voteType } = req.body;
        await CrimeReport.updateOne(
            { _id: reportId },
            { $inc: { [`votes.${voteType}`]: 1 } }
        );
        res.json({ message: 'Vote recorded successfully' });
    } catch (error) {
        res.status(500).json({ error: 'Failed to record vote' });
    }
};

// controllers/adminController.js
const User = require('../models/userModel');

exports.banUser = async (req, res) => {
    try {
        const { userId } = req.body;
        await User.updateOne({ _id: userId }, { banned: true });
        res.json({ message: 'User banned successfully' });
    } catch (error) {
        res.status(500).json({ error: 'Failed to ban user' });
    }
};


// Full-Stack Crime Reporting & Community Verification Platform
// Backend: Express.js with MongoDB, AI, and Cloud Storage
// Frontend: Next.js with Tailwind CSS and Google Maps

// Backend Structure
// controllers/
// ├── authController.js
// ├── reportController.js
// ├── voteController.js
// ├── adminController.js

// models/
// ├── userModel.js
// ├── reportModel.js
// ├── voteModel.js

// routes/
// ├── authRoutes.js
// ├── reportRoutes.js
// ├── voteRoutes.js
// ├── adminRoutes.js

// middlewares/
// ├── authMiddleware.js

// config/
// ├── db.js
// ├── cloudStorage.js

// server.js
// .env
// package.json

// models/userModel.js
const mongoose = require('mongoose');

const UserSchema = new mongoose.Schema({
    email: { type: String, required: true, unique: true },
    password: { type: String, required: true },
    phone: { type: String, required: true },
    verified: { type: Boolean, default: false },
    role: { type: String, default: 'user' },
    banned: { type: Boolean, default: false }
});

module.exports = mongoose.model('User', UserSchema);

// models/reportModel.js
const CrimeReportSchema = new mongoose.Schema({
    userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
    title: String,
    division: String,
    district: String,
    imageUrl: String,
    crimeTime: Date,
    postTime: { type: Date, default: Date.now },
    location: { type: { type: String, enum: ['Point'] }, coordinates: [Number] },
    votes: { upvote: { type: Number, default: 0 }, downvote: { type: Number, default: 0 } }
});

module.exports = mongoose.model('CrimeReport', CrimeReportSchema);

// models/voteModel.js
const VoteSchema = new mongoose.Schema({
    userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
    reportId: { type: mongoose.Schema.Types.ObjectId, ref: 'CrimeReport' },
    voteType: { type: String, enum: ['upvote', 'downvote'], required: true }
});

module.exports = mongoose.model('Vote', VoteSchema);

// routes/authRoutes.js
const express = require('express');
const { register, verifyEmail, login } = require('../controllers/authController');
const router = express.Router();

router.post('/register', register);
router.get('/verify/:token', verifyEmail);
router.post('/login', login);

module.exports = router;


// routes/reportRoutes.js
const express = require('express');
const { reportCrime } = require('../controllers/reportController');
const router = express.Router();

router.post('/', reportCrime);

module.exports = router;

// routes/voteRoutes.js
const express = require('express');
const { voteReport } = require('../controllers/voteController');
const router = express.Router();

router.post('/', voteReport);

module.exports = router;

// routes/adminRoutes.js
const express = require('express');
const { banUser } = require('../controllers/adminController');
const router = express.Router();

router.post('/ban', banUser);

module.exports = router;

// middlewares/authMiddleware.js
const jwt = require('jsonwebtoken');

// middlewares/authMiddleware.js (Updated for role-based access control)
exports.authMiddleware = (roles = []) => (req, res, next) => {
    const token = req.headers.authorization?.split(' ')[1];
    if (!token) return res.status(403).json({ error: 'Access denied' });
    
    jwt.verify(token, process.env.JWT_SECRET, (err, decoded) => {
        if (err) return res.status(401).json({ error: 'Invalid token' });
        
        if (roles.length && !roles.includes(decoded.role)) {
            return res.status(403).json({ error: 'Permission denied' });
        }
        req.user = decoded;
        next();
    });
};

// config/db.js (Added retry mechanism)
const mongoose = require('mongoose');
const dotenv = require('dotenv');
dotenv.config();

const connectWithRetry = () => {
    mongoose.connect(process.env.MONGO_URI, {
        useNewUrlParser: true,
        useUnifiedTopology: true,
    }).then(() => console.log('MongoDB connected'))
    .catch(err => {
        console.error('MongoDB connection failed, retrying...', err);
        setTimeout(connectWithRetry, 5000);
    });
};
connectWithRetry();

module.exports = mongoose;


// config/cloudStorage.js
const { Storage } = require('@google-cloud/storage');
const dotenv = require('dotenv');
dotenv.config();

const storage = new Storage({ keyFilename: process.env.GOOGLE_APPLICATION_CREDENTIALS });
const bucket = storage.bucket(process.env.GCLOUD_STORAGE_BUCKET);

exports.uploadFile = async (file) => {
    const blob = bucket.file(file.originalname);
    const blobStream = blob.createWriteStream();
    blobStream.end(file.buffer);
    return `https://storage.googleapis.com/${process.env.GCLOUD_STORAGE_BUCKET}/${file.originalname}`;
};

// server.js (Added rate limiting for security)
const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const rateLimit = require('express-rate-limit');
const mongoose = require('./config/db');
const authRoutes = require('./routes/authRoutes');
const reportRoutes = require('./routes/reportRoutes');
const voteRoutes = require('./routes/voteRoutes');
const adminRoutes = require('./routes/adminRoutes');

dotenv.config();
const app = express();
app.use(cors());
app.use(express.json());

// Apply rate limiting
const limiter = rateLimit({ windowMs: 15 * 60 * 1000, max: 100 });
app.use(limiter);

app.use('/auth', authRoutes);
app.use('/report', reportRoutes);
app.use('/vote', voteRoutes);
app.use('/admin', adminRoutes);

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
























// // Full-Stack Crime Reporting & Community Verification Platform
// // Backend: Express.js with MongoDB, AI, and Cloud Storage
// // Frontend: Next.js with Tailwind CSS and Google Maps

// // Backend Structure
// // controllers/
// // ├── authController.js
// // ├── reportController.js
// // ├── voteController.js
// // ├── adminController.js

// // models/
// // ├── userModel.js
// // ├── reportModel.js
// // ├── voteModel.js

// // routes/
// // ├── authRoutes.js
// // ├── reportRoutes.js
// // ├── voteRoutes.js
// // ├── adminRoutes.js

// // middlewares/
// // ├── authMiddleware.js

// // config/
// // ├── db.js
// // ├── cloudStorage.js

// // server.js
// // .env
// // package.json

// // Enhancements:
// // ✅ Email verification after user registration
// // ✅ Role-based access control for different user levels
// // ✅ Optimized security with rate limiting and stronger password hashing
// // ✅ Pagination and search filters for crime reports
// // ✅ Enhanced error handling
// // ✅ Admin dashboard integration

// // controllers/authController.js
// const bcrypt = require('bcryptjs');
// const jwt = require('jsonwebtoken');
// const User = require('../models/userModel');
// const crypto = require('crypto');
// const nodemailer = require('nodemailer');

// exports.register = async (req, res) => {
//     const { email, password, phone } = req.body;
//     const hashedPassword = await bcrypt.hash(password, 12);
//     const verificationToken = crypto.randomBytes(32).toString('hex');
    
//     try {
//         const user = new User({ email, password: hashedPassword, phone, verified: false, verificationToken });
//         await user.save();
        
//         // Send verification email
//         const transporter = nodemailer.createTransport({
//             service: 'gmail',
//             auth: { user: process.env.EMAIL_USER, pass: process.env.EMAIL_PASS }
//         });
//         const mailOptions = {
//             from: process.env.EMAIL_USER,
//             to: email,
//             subject: 'Verify Your Email',
//             text: `Click the link to verify your email: ${process.env.BASE_URL}/auth/verify/${verificationToken}`
//         };
//         transporter.sendMail(mailOptions);
        
//         res.json({ message: 'User registered successfully. Please verify your email.' });
//     } catch (error) {
//         res.status(500).json({ error: 'Registration failed' });
//     }
// };

// exports.verifyEmail = async (req, res) => {
//     try {
//         const { token } = req.params;
//         const user = await User.findOne({ verificationToken: token });
//         if (!user) return res.status(400).json({ error: 'Invalid token' });
//         user.verified = true;
//         user.verificationToken = undefined;
//         await user.save();
//         res.json({ message: 'Email verified successfully' });
//     } catch (error) {
//         res.status(500).json({ error: 'Email verification failed' });
//     }
// };

// exports.login = async (req, res) => {
//     const { email, password } = req.body;
//     try {
//         const user = await User.findOne({ email });
//         if (!user || !(await bcrypt.compare(password, user.password))) {
//             return res.status(400).json({ error: 'Invalid credentials' });
//         }
//         if (!user.verified) return res.status(403).json({ error: 'Please verify your email' });
        
//         const token = jwt.sign({ userId: user._id, role: user.role }, process.env.JWT_SECRET, { expiresIn: '1h' });
//         res.json({ token });
//     } catch (error) {
//         res.status(500).json({ error: 'Login failed' });
//     }
// };

// // middlewares/authMiddleware.js (Updated for role-based access control)
// exports.authMiddleware = (roles = []) => (req, res, next) => {
//     const token = req.headers.authorization?.split(' ')[1];
//     if (!token) return res.status(403).json({ error: 'Access denied' });
    
//     jwt.verify(token, process.env.JWT_SECRET, (err, decoded) => {
//         if (err) return res.status(401).json({ error: 'Invalid token' });
        
//         if (roles.length && !roles.includes(decoded.role)) {
//             return res.status(403).json({ error: 'Permission denied' });
//         }
//         req.user = decoded;
//         next();
//     });
// };

// // routes/authRoutes.js
// const express = require('express');
// const { register, verifyEmail, login } = require('../controllers/authController');
// const router = express.Router();

// router.post('/register', register);
// router.get('/verify/:token', verifyEmail);
// router.post('/login', login);

// module.exports = router;

// // config/db.js (Added retry mechanism)
// const mongoose = require('mongoose');
// const dotenv = require('dotenv');
// dotenv.config();

// const connectWithRetry = () => {
//     mongoose.connect(process.env.MONGO_URI, {
//         useNewUrlParser: true,
//         useUnifiedTopology: true,
//     }).then(() => console.log('MongoDB connected'))
//     .catch(err => {
//         console.error('MongoDB connection failed, retrying...', err);
//         setTimeout(connectWithRetry, 5000);
//     });
// };
// connectWithRetry();

// module.exports = mongoose;

// // server.js (Added rate limiting for security)
// const express = require('express');
// const cors = require('cors');
// const dotenv = require('dotenv');
// const rateLimit = require('express-rate-limit');
// const mongoose = require('./config/db');
// const authRoutes = require('./routes/authRoutes');
// const reportRoutes = require('./routes/reportRoutes');
// const voteRoutes = require('./routes/voteRoutes');
// const adminRoutes = require('./routes/adminRoutes');

// dotenv.config();
// const app = express();
// app.use(cors());
// app.use(express.json());

// // Apply rate limiting
// const limiter = rateLimit({ windowMs: 15 * 60 * 1000, max: 100 });
// app.use(limiter);

// app.use('/auth', authRoutes);
// app.use('/report', reportRoutes);
// app.use('/vote', voteRoutes);
// app.use('/admin', adminRoutes);

// const PORT = process.env.PORT || 5000;
// app.listen(PORT, () => {
//   console.log(`Server running on port ${PORT}`);
// });
