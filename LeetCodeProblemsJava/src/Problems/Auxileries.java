package Problems;

public class Auxileries {
    static void Print(ListNode head){
        while(head != null){
            System.out.print(head.val+",");
            head = head.next;
        }
        System.out.println();
    }
}
