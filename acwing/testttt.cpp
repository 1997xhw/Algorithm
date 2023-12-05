import java.util.Scanner;
import java.util.TreeSet;
import java.util.Iterator;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();  ###将读入的整数赋值给n
        TreeSet<Integer> ts = new TreeSet<>();
        for(int i = 0; i < n; i++) {
            ts.add(scan.nextInt());  ###读入n个整数
        }
        System.out.println(ts.size());  ###输出M
        Iterator<Integer> it = ts.iterator();
        while(it.hasNext()) {
            System.out.print(it.next());  ###输出M个整数
            if(it.hasNext()) System.out.print(" ");  ###根据情况添加空格
        }
    }
}

#