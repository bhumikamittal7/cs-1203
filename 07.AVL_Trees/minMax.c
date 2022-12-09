
//AVL tree minimum
NodeAddress minimum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> left)
        x = x -> left;
    return x;
}

//AVL tree maximum
NodeAddress maximum (NodeAddress root)
{
    NodeAddress x = root;
    while (x -> right)
        x = x -> right;
    return x;
}
