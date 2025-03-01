class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        queue<Node *> q;
        q.push(root);
        bool leftToRight = false; // Flag to toggle the direction of traversal

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size); // Vector to store nodes at current level

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                // Insert the node in the vector based on the direction
                if (leftToRight)
                {
                    level[i] = node->data;
                }
                else
                {
                    level[size - i - 1] = node->data;
                }

                // Push the left and right children to the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Add the current level to the final result
            for (int i = 0; i < size; i++)
            {
                ans.push_back(level[i]);
            }

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return ans;
    }
};