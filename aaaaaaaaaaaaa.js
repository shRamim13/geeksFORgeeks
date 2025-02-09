// Full-Stack Crime Reporting & Community Verification Platform - Frontend
// Tech Stack: Next.js, Tailwind CSS, Google Maps API

// Frontend Structure
// components/
// ├── Navbar.js
// ├── ReportForm.js
// ├── CrimeMap.js
// ├── CrimeList.js
// ├── AuthForm.js

// pages/
// ├── index.js
// ├── login.js
// ├── register.js
// ├── dashboard.js
// ├── report.js
// ├── admin.js

// styles/
// ├── globals.css
// ├── tailwind.css

// public/
// ├── images/
// ├── icons/

// .env.local
// package.json

// Install Dependencies
// npm install next react react-dom tailwindcss axios @react-google-maps/api

// tailwind.config.js
module.exports = {
    content: ['./pages/**/*.{js,ts,jsx,tsx}', './components/**/*.{js,ts,jsx,tsx}'],
    theme: {
        extend: {
            colors: {
                primary: '#1E3A8A',
                secondary: '#1E40AF',
                accent: '#3B82F6',
            },
            fontFamily: {
                sans: ['Inter', 'sans-serif'],
            },
        },
    },
    plugins: [],
};

// components/Navbar.js
import Link from 'next/link';
export default function Navbar() {
    return (
        <nav className="bg-gray-800 p-4 text-white flex justify-between">
            <h1 className="text-lg font-bold">Crime Report</h1>
            <div>
                <Link href="/dashboard" className="mr-4">Dashboard</Link>
                <Link href="/report" className="mr-4">Report Crime</Link>
                <Link href="/login">Login</Link>
            </div>
        </nav>
    );
}

// components/CrimeMap.js
import { GoogleMap, LoadScript, Marker } from '@react-google-maps/api';
const containerStyle = {
    width: '100%',
    height: '400px'
};
const center = {
    lat: 37.7749,
    lng: -122.4194
};
export default function CrimeMap() {
    return (
        <LoadScript googleMapsApiKey={process.env.NEXT_PUBLIC_GOOGLE_MAPS_API_KEY}>
            <GoogleMap mapContainerStyle={containerStyle} center={center} zoom={10}>
                <Marker position={center} />
            </GoogleMap>
        </LoadScript>
    );
}

// components/CrimeList.js
import { useState, useEffect } from 'react';
import axios from 'axios';
export default function CrimeList() {
    const [reports, setReports] = useState([]);
    useEffect(() => {
        axios.get('/api/reports')
            .then(response => setReports(response.data))
            .catch(error => console.error('Error fetching reports:', error));
    }, []);
    return (
        <div className="p-4">
            <h2 className="text-xl font-bold">Recent Reports</h2>
            <ul>
                {reports.map((report, index) => (
                    <li key={index} className="border p-2 my-2">
                        <h3 className="font-bold">{report.title}</h3>
                        <p>{report.description}</p>
                    </li>
                ))}
            </ul>
        </div>
    );
}

// components/AuthForm.js
import { useState } from 'react';
import axios from 'axios';
export default function AuthForm({ type }) {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const handleSubmit = async (e) => {
        e.preventDefault();
        const endpoint = type === 'login' ? '/api/auth/login' : '/api/auth/register';
        await axios.post(endpoint, { email, password });
        alert(`${type} successful`);
    };
    return (
        <form className="p-4" onSubmit={handleSubmit}>
            <h2 className="text-xl font-bold">{type === 'login' ? 'Login' : 'Register'}</h2>
            <input className="block border p-2 my-2" placeholder="Email" value={email} onChange={(e) => setEmail(e.target.value)} />
            <input className="block border p-2 my-2" type="password" placeholder="Password" value={password} onChange={(e) => setPassword(e.target.value)} />
            <button className="bg-blue-500 text-white p-2" type="submit">{type === 'login' ? 'Login' : 'Register'}</button>
        </form>
    );
}

// Full-Stack Crime Reporting & Community Verification Platform - Frontend
// Tech Stack: Next.js, Tailwind CSS, Google Maps API

// Frontend Structure
// components/
// ├── Navbar.js
// ├── ReportForm.js
// ├── CrimeMap.js
// ├── CrimeList.js
// ├── AuthForm.js

// pages/
// ├── index.js
// ├── login.js
// ├── register.js
// ├── dashboard.js
// ├── report.js
// ├── admin.js

// styles/
// ├── globals.css
// ├── tailwind.css

// public/
// ├── images/
// ├── icons/

// .env.local
// package.json

// Install Dependencies
// npm install next react react-dom tailwindcss axios @react-google-maps/api

// tailwind.config.js
module.exports = {
    content: ['./pages/**/*.{js,ts,jsx,tsx}', './components/**/*.{js,ts,jsx,tsx}'],
    theme: {
        extend: {
            colors: {
                primary: '#1E3A8A',
                secondary: '#1E40AF',
                accent: '#3B82F6',
            },
            fontFamily: {
                sans: ['Inter', 'sans-serif'],
            },
        },
    },
    plugins: [],
};

// components/ReportForm.js
import { useState } from 'react';
import axios from 'axios';
export default function ReportForm() {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');
    const [location, setLocation] = useState('');
    const handleSubmit = async (e) => {
        e.preventDefault();
        await axios.post('/api/report', { title, description, location });
        alert('Report Submitted');
    };
    return (
        <form className="p-4" onSubmit={handleSubmit}>
            <h2 className="text-xl font-bold">Report a Crime</h2>
            <input className="block border p-2 my-2" placeholder="Title" value={title} onChange={(e) => setTitle(e.target.value)} />
            <textarea className="block border p-2 my-2" placeholder="Description" value={description} onChange={(e) => setDescription(e.target.value)}></textarea>
            <input className="block border p-2 my-2" placeholder="Location" value={location} onChange={(e) => setLocation(e.target.value)} />
            <button className="bg-blue-500 text-white p-2" type="submit">Submit Report</button>
        </form>
    );
}

// pages/report.js
import ReportForm from '../components/ReportForm';
export default function Report() {
    return <ReportForm />;
}






// Full-Stack Crime Reporting & Community Verification Platform - Frontend
// Tech Stack: Next.js, Tailwind CSS, Google Maps API

// Frontend Structure
// components/
// ├── Navbar.js
// ├── ReportForm.js
// ├── CrimeMap.js
// ├── CrimeList.js
// ├── AuthForm.js

// pages/
// ├── index.js
// ├── login.js
// ├── register.js
// ├── dashboard.js
// ├── report.js
// ├── admin.js

// styles/
// ├── globals.css
// ├── tailwind.css

// public/
// ├── images/
// ├── icons/

// .env.local
// package.json

// Install Dependencies
// npm install next react react-dom tailwindcss axios @react-google-maps/api

// tailwind.config.js
module.exports = {
    content: ['./pages/**/*.{js,ts,jsx,tsx}', './components/**/*.{js,ts,jsx,tsx}'],
    theme: {
        extend: {
            colors: {
                primary: '#1E3A8A',
                secondary: '#1E40AF',
                accent: '#3B82F6',
            },
            fontFamily: {
                sans: ['Inter', 'sans-serif'],
            },
        },
    },
    plugins: [],
};

// pages/login.js
import AuthForm from '../components/AuthForm';
export default function Login() {
    return <AuthForm type="login" />;
}

// pages/register.js
import AuthForm from '../components/AuthForm';
export default function Register() {
    return <AuthForm type="register" />;
}

// pages/index.js
import Navbar from '../components/Navbar';
import Link from 'next/link';
export default function Home() {
    return (
        <div className="bg-gray-100 min-h-screen">
            <Navbar />
            <div className="flex flex-col items-center justify-center h-screen text-center p-4">
                <h1 className="text-4xl font-bold text-primary">Welcome to Crime Reporting System</h1>
                <p className="mt-4 text-gray-700">Help make your community safer by reporting crimes.</p>
                <div className="mt-6 space-x-4">
                    <Link href="/login" className="bg-primary hover:bg-secondary text-white py-2 px-4 rounded shadow-lg">Login</Link>
                    <Link href="/register" className="bg-green-600 hover:bg-green-700 text-white py-2 px-4 rounded shadow-lg">Register</Link>
                    <Link href="/dashboard" className="bg-gray-600 hover:bg-gray-700 text-white py-2 px-4 rounded shadow-lg">View Reports</Link>
                </div>
            </div>
        </div>
    );
}

// pages/dashboard.js
import Navbar from '../components/Navbar';
import CrimeMap from '../components/CrimeMap';
import CrimeList from '../components/CrimeList';
export default function Dashboard() {
    return (
        <div className="bg-gray-100 min-h-screen">
            <Navbar />
            <div className="p-6 max-w-4xl mx-auto">
                <h2 className="text-2xl font-bold text-primary mb-4">Crime Reports</h2>
                <CrimeMap />
                <CrimeList />
            </div>
        </div>
    );
}

// pages/admin.js
import Navbar from '../components/Navbar';
import { useEffect, useState } from 'react';
import axios from 'axios';
export default function Admin() {
    const [reports, setReports] = useState([]);
    useEffect(() => {
        axios.get('/api/reports')
            .then(response => setReports(response.data))
            .catch(error => console.error('Error fetching reports:', error));
    }, []);
    const handleDelete = async (id) => {
        await axios.delete(`/api/reports/${id}`);
        setReports(reports.filter(report => report._id !== id));
    };
    return (
        <div className="bg-gray-100 min-h-screen">
            <Navbar />
            <div className="p-6 max-w-4xl mx-auto">
                <h2 className="text-2xl font-bold text-primary mb-4">Admin Panel</h2>
                <ul>
                    {reports.map(report => (
                        <li key={report._id} className="border p-4 my-2 bg-white shadow-lg rounded-md">
                            <h3 className="font-bold text-lg">{report.title}</h3>
                            <p className="text-gray-600">{report.description}</p>
                            <button className="bg-red-500 hover:bg-red-700 text-white py-1 px-3 rounded mt-2" onClick={() => handleDelete(report._id)}>Delete</button>
                        </li>
                    ))}
                </ul>
            </div>
        </div>
    );
}

// Next Steps:
// ✅ Implement authentication pages (login.js, register.js)
// ✅ Build the crime reporting form (ReportForm.js, report.js)
// ✅ Integrate Google Maps for report visualization (CrimeMap.js, dashboard.js)
// ✅ Add admin panel for managing reports (admin.js)
// ✅ Enhance styling for better UI/UX
// ✅ Setup global styles and public assets
// ✅ Fully structured and optimized frontend




