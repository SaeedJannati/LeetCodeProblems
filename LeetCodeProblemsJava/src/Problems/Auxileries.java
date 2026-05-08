package Problems;

public class Auxileries {
    static void Print(ListNode head) {
        while (head != null) {
            System.out.print(head.val + ",");
            head = head.next;
        }
        System.out.println();
    }
static void Print(int[] input){
        IO.print("{");
        for (var num:input){
            IO.print(num+",");
        }
        IO.println("}");
}
    static <T> void Print(T[][] array) {
        IO.println("[");
        for (int i = 0; i < array.length; i++) {
            IO.print("[");
            for (int j = 0; j < array[i].length; j++) {
                IO.print(array[i][j] + ",");
            }
            IO.println("],");
        }
        IO.println("]");
    }
}
