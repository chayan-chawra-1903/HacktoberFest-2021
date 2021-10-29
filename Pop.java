import java.util.*;  
  
public class StackPopDemo   
{  
    /* Driver Code */  
    public static void main(String args[])  
    {  
        /* an empty Stack created. */  
        Stack<String> stk = new Stack<String>();  
  
        /* push() method is used to add elements. */  
        stk.push("My");  
        stk.push("First");  
        stk.push("Stack");  
        stk.push("Implementation");  
        /* Display the contents of Stack */  
        System.out.println("Contents of Stack after addition of elements: " + stk);  
        /* Delete elements of stack using pop() method. */  
        System.out.println("Popped element 1: " +stk.pop());  
        System.out.println("Popped element 2: " +stk.pop());  
        /* Display the Stack after deletion. */  
        System.out.println("Contents of Stack after deletion of elements: " + stk);  
    }  
}  
