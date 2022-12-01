/*
Stacks -- Last in first out (LIFO) data structure
    - push() -- insert an element
    - pop()  -- extract an element
    - top()  -- return the top element
    - empty() -- return true if the stack is empty
    - full()  -- return true if the stack is full

Queues -- First in first out (FIFO) data structure
    - insert() -- insert an element     (enqueue - happens at the end - add to the tail)
    - extract()  -- extract an element  (dequeue - happens at the front - return head and update head)
    - front()  -- return the front element
    - empty() -- return true if the queue is empty
    - full()  -- return true if the queue is full
*/

//Queue 
/*
max = 7
n = 0
start = 0
end = 0

insert(11)
    q->data[ (q->start + q->n++) ] =  val;
    q->data[ (0 + 0++) ] =  11;
    q->data[ 0 ] =  3;
    q->n = 1

max = 7
n = 1
start = 0 (remains where it is)
end = 1

insert(22)
    q->data[ (q->start + q->n++) ] =  val;
    q->data[ (0 + 1++) ] =  22;
    q->data[ 1 ] =  22;
    q->n = 2

max = 7
n = 2
start = 0 (remains where it is)
end = 2

if (n == max)  return;
q[(start+n)%max] = val; n = n+1;

int val = q[start]; 
start = (start+1)%max; 
n = n-1; 
return val;
*/

//POST PRE Notations
/*
(5+4) * (9 - 2^3)
Infix: 5 + 4 * 9 - 2^3              (left-root-right)
Postfix: 5 4 + 9 2 3 ^ - *          (left-right-root)
Prefix: * + 5 4 - 9 ^ 2 3           (root-left-right)
*/

