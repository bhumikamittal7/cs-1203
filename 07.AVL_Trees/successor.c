
//AVL tree minimum
NodeAddress minimum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> left)
        x = x -> left;
    return x;
}

//AVL tree successor
NodeAddress successor (NodeAddress x)
{
    if (x -> right)
        return minimum (x -> right);
    NodeAddress y = x -> parent;
    while (y && x == y -> right)
    {
        x = y;
        y = y -> parent;
    }
    return y;
}
