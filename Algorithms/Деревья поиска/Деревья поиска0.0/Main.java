import java.io.*;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
   // Дано бинарное поисковое дерево, в котором ключи вершин являются целыми числами в диапазоне от −2^31 до 2^31-11 включительно.
   // Найдите сумму ключей всех вершин дерева.
    public static void main(String[] args) throws IOException {
	// write your code here
        TreeSet<Integer> tree=new TreeSet<>();
        try (Scanner sc= new Scanner(new File("input.txt"))){
            while(sc.hasNext()){
                tree.add(sc.nextInt());
            }
        }
        long sum=0;
        for(Integer elem: tree){
            sum+=elem;
        }
        PrintWriter writer=new PrintWriter(new FileWriter("output.txt"));
        writer.println(sum);
        writer.close();
    }
}
