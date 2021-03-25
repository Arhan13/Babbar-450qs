/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {

        //BFS Approach
        //We need to traverse the graph first
        //We will use BFS or DFS
        if (!node)
        {
            return NULL;
        }
        Node *copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node *> todo;
        todo.push(node);
        while (!todo.empty())
        {
            //Setting the current node
            Node *current = todo.front();
            //poping it off so that it isn't repeated again
            todo.pop();
            //Looking through all the neighbours of the node to look for new node which have not
            //been discovered yet
            for (Node *neighbor : current->neighbors)
            {
                //If the neighbour isn't present then all it to the list
                if (copies.find(neighbor) == copies.end())
                {
                    copies[neighbor] = new Node(neighbor->val, {});
                    //We have registered the node
                    todo.push(neighbor);
                }
                //Updating the neighbors of the current node
                copies[current]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }

private:
    unordered_map<Node *, Node *> copies;
};