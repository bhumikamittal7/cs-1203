//transplant function
void transplant (NodeAddress u, NodeAddress v)
{
    if (!u -> parent)
        root = v;
    else if (u == u -> parent -> left)
        u -> parent -> left = v;
    else
        u -> parent -> right = v;
    if (v)
        v -> parent = u -> parent;
}

//AVL tree deletion
NodeAddress delete (NodeAddress root, int val)
{
    NodeAddress x = root;
    while (x && x -> val != val)
    {
        if (val < x -> val)
            x = x -> left;
        else
            x = x -> right;
    }
    if (!x)
        return root;
    if (!x -> left)
        transplant (x, x -> right);
    else if (!x -> right)
        transplant (x, x -> left);
    else
    {
        NodeAddress y = minimum (x -> right);
        if (y -> parent != x)
        {
            transplant (y, y -> right);
            y -> right = x -> right;
            y -> right -> parent = y;
        }
        transplant (x, y);
        y -> left = x -> left;
        y -> left -> parent = y;

    }
    return root;
}

