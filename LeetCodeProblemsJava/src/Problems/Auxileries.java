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
        System.out.print("{");
        for (var num:input){
            System.out.print(num+",");
        }
        System.out.println("}");
}
    static <T> void Print(T[][] array) {
        System.out.println("[");
        for (int i = 0; i < array.length; i++) {
            System.out.print("[");
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j] + ",");
            }
            System.out.println("],");
        }
        System.out.println("]");
    }
}
