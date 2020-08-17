# Cpp-LAB-Exercises

## In this repo I implemented C++ Exersices and Solutions of the course of C++.
## The labs are from many universities all around the world (USA,Lebanon,Egypt and Marroco).
## Used IDE: Code::Blocks 17.3

### Question 1
Write a C++ code to take two linked lists, and returns true if the linked lists are disjoint, i.e. have no elements in common.

### Question 2
![BinaryTree](https://github.com/alialhousseini/Cpp-LAB-Exercises/tree.png)
Given the above binary tree, write a program that do the following:
- Print the nodes in a preorder sequence and while printing the preorder, insert the nodes into a second binary tree.
- Print the nodes in a postorder sequence and while printing the postorder, insert the nodes into a second binary tree.
- Insert the modes of a binary tree into an ordered linked list.

### Question 3
Write a C++ code that asks the user to enter a line of text as " Welcome To Data Structure Module ", then changes each uppercase letter to lowercase, and then places the letters after conversion in a circular queue. The program should then test whether the line of text is a palindrome or not.

### Question 4
You have a file contains 5 words "I love introduction to Programming". Write a program that does the following:
- Read the words from the file and save them in a string array.
- Implement a function to search for a certain word entered by the user then return its index.
- Print the index returned by the search function in a file.

### Question 5
You have a file contains 5 integers "1,2,3,4,5". Write a program that does the following:
- Read the integers from the file and save them in a string array.
- Implement a function to search for a certain number entered by the user then return its index.
- Print the index returned by the search function in a file.

### Question 6
You have 3 employees each has 3 salaries for 3 months (3x3) Array. Write a program that does the following:
- Implmenet the employees data using a 2D array structure and get is values from the user.
- Calculate the summation of the salaries of the 3 months for each employee and save them in 1D array. Use a for loop statement to implement this calculation.
- Implement a function to calculate the average salary for each employee.
- Write the average salary for each employee in a file.

### Question 7
You have a file contains 5 integers of values 1,2,3,4 and 5. Write a program that does the following:
- Read values from file and save them in an array.
- Implement a function to find the average of all integers in the array.
- Store the factorial of the average in another file.

### Question 8
Most sorting algorithms, like bubble, insertion, selection and shell follow similar implementations.  Radix sort is a unique sorting algorithm using the radix of a number to sort.  Use the Numbers.txt file for the numbers to sort.  
Specification:
- Create an array using your DoublyLinkedList from Lab0 with 10 positions (0 thru 9).
- The 10 positions in the array are used for the digits 0 thru 9.  
- Read the Numbers.txt file and sort them using the Radix Sort algorithm.
- As progressing through the radix of each number, place the number in the appropriate array position.

### Question 9
Write an algorithm to determine if a Binary Tree is Level Balanced.
Balanced tree
Level 1: 42
Level 2: 25 68
Level 3: 1 35 63 70
Level 4: - - - - 59 65 - 79

Levels 1 thru 3 are balanced. Level 4 is considered balanced. The missing numbers are in on the last level (Level 4)

Unbalanced tree
Level 1: 42 
Level 2: 35 68 
Level 3: 1 - 59 70 
Level 4: - 25 - - - 63 - 79 
Level 5: - - - - - - - - - - - 65 - - - - 

Use some node rotation algorithms, like AVL rotations, to balance the unbalanced levels. An AVL Left-Right rotation can fix the 35,1,25 node levels. An AVL Left-Left rotation can fix the 59,63,65 node levels.
Your program should be able to determine which level needs to be balanced, and then apply the appropriate rotations to balance the tree. For simplicity, use the same number set as shown in the TreeArray example:
original numbers as shown in slides set = { 42, 68, 35, 1, 70, 25, 79, 59, 63, 65 }
- Construct a balanced tree by using this ordering of the numbers from the TreeArray example and verify your program produces a balanced tree:
level ordered numbers set = { 42, 25, 68, 1, 35, 63, 70, 59, 65, 79 }
- Then construct a unbalanced tree by using the original number set, and verify that the Left-Right and Left-Left rotations as mentioned above, make the tree level balanced. 
- Reorder the number set to something other than the original number set or the ordered numbers. Your algorithm should note which level requires balancing and then determine the best rotation algorithms. After performing the rotation(s), verify the tree is re-balanced.
- Note that this ordering: { 1, 25, 35, 42, 59, 63, 65, 68, 70, 79 } will produce a degenerate tree with all the nodes leaning to the right, making it essentially a linked list. This ordering will require many rotations. This is beyond the scope of the assignment. Pick an ordering that produces only one or two rotations.
- In each case, output the tree before the rotations (if needed) and after the the rotations are completed.  Preferably use your horizontal tree output function from Lab3 to display your trees in level order.
