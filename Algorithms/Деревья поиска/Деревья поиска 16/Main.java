import java.io.*;
import java.util.Scanner;

//Необходимо удалить (правым удалением) корень дерева,
//а затем для каждой вершины определить, сколько наибольших полупутей проходят через неё.
public class Main implements Runnable {
    @Override
    public void run() {
        BinaryTree tree = null;
        try {
            tree = new BinaryTree();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (Scanner sc = new Scanner(new File("input.txt"))) {
            int root_=sc.nextInt();
            tree.add(root_);
            while (sc.hasNext()) {
                tree.add(sc.nextInt());
            }
           tree.delete(root_);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        tree.traversePostOrder();
        tree.setB();
        tree.setA();
        tree.traversePreOrder();
    }

    private static class BinaryTree {
        private BinaryTree() throws IOException {
            writer = new PrintWriter(new FileWriter("output.txt"));
        }

        private class Node {
            private int value;
            private Node left;
            private Node right;
            private int h;   //высоту
            private int l;   // число листьев
            private int b; //число b(v) попарно различных полупутей длины MSL(T),
            private int msl_;
            private int a;
            private int numberPaths;
            Node(int value) {
                this.value = value;
                right = null;
                left = null;
            }
        }

        Node root;
        int msl=0;
        PrintWriter writer;

        private Node addRecursive(Node current, int value) {
            if (current == null) {
                return new Node(value);
            }
            int compare = Integer.compare(value, current.value);
            if (compare < 0) {
                current.left = addRecursive(current.left, value);
            } else if (compare > 0) {
                current.right = addRecursive(current.right, value);
            }
            return current;
        }

        public void add(int value) {
            root = addRecursive(root, value);
        }

        private void traversePreOrderRecursive(Node node) {
            if (node != null) {
                writer.println(node.value+" "+node.numberPaths);
                traversePreOrderRecursive(node.left);
                traversePreOrderRecursive(node.right);
            }
        }

        public void traversePreOrder() {
            traversePreOrderRecursive(root);
            writer.close();
        }
        private void setARecursive(Node node) {
            if (node != null) {
                if(node==root){
                    root.a=0;
                }
                if(node.left!=null && node.right==null){
                    node.left.a=node.a+node.b;
                }else if(node.right!=null && node.left==null){
                    node.right.a=node.a+node.b;
                }else if(node.right!=null && node.left!=null){
                    if(node.right.h>node.left.h){
                        node.right.a=node.a+node.b;
                        node.left.a=node.b;
                    }else if(node.left.h>node.right.h){
                        node.left.a=node.a+node.b;
                        node.right.a=node.b;
                    }else {
                        node.right.a=node.b+node.right.l*(node.a/node.l);
                        node.left.a=node.b+node.left.l*(node.a/node.l);
                    }
                }
                node.numberPaths=node.a+node.b;
                setARecursive(node.left);
                setARecursive(node.right);
            }
        }

        public void setA() {
            setARecursive(root);
        }

        private int findMin(Node root) {
            if (root.left == null) {
                return root.value;
            } else {
                return findMin(root.left);
            }
        }

        private Node deleteRecursive(Node current, int value) {
            if (current == null) {
                return null;
            }

            if (value == current.value) {
                if (current.left == null && current.right == null) {
                    return null;
                }
                if (current.right == null) {
                    return current.left;
                }
                if (current.left == null) {
                    return current.right;
                }
                int min = findMin(current.right);
                current.value = min;
                current.right = deleteRecursive(current.right, min);
                return current;

            }
            if (value < current.value) {
                current.left = deleteRecursive(current.left, value);
                return current;
            }
            current.right = deleteRecursive(current.right, value);
            return current;
        }

        public void delete(int value) {
            root = deleteRecursive(root, root.value);
        }
        private void traversePostOrderRecursive(Node node) { //setting h and l and msl
            if (node != null) {
                traversePostOrderRecursive(node.left);
                traversePostOrderRecursive(node.right);
                if (node.left==null && node.right==null){
                    node.h=0;
                    node.l=1;
                    node.msl_=0;
                    node.numberPaths=1;
                }else if(node.left!=null && node.right==null){
                    node.h=node.left.h+1;
                    node.l=node.left.l;
                    node.msl_=node.h;
                    if(node.msl_>msl){
                        msl=node.h;
                    }
                }else if(node.right!=null && node.left==null){
                    node.h=node.right.h+1;
                    node.l=node.right.l;
                    node.msl_=node.h;
                    if(node.msl_>msl){
                        msl=node.h;
                    }
                }else if(node.left!=null && node.right!=null){
                    node.h=Math.max(node.left.h,node.right.h)+1;
                    node.msl_=node.left.h+node.right.h+2;
                    if(node.msl_>msl){
                        msl=node.msl_;
                    }
                    if(node.left.h==node.right.h){
                        node.l=node.left.l+node.right.l;
                    }else{
                        node.l=Math.max(node.right.l,node.left.l);
                    }
                }
            }
        }
        public void traversePostOrder(){
            traversePostOrderRecursive(root);
        }
        private void setBRecursive(Node node){
            if (node != null) {
                setBRecursive(node.left);
                setBRecursive(node.right);
                if(node.msl_!=msl){
                    node.b=0;
                }else {
                    if (node.left != null && node.right != null) {
                        node.b = node.left.l * node.right.l;
                    } else if (node.left != null && node.right == null) {
                        node.b = node.left.l;
                    } else if (node.left==null && node.right!=null) {
                        node.b=node.right.l;
                    }else{
                        node.b=1;
                    }
                }
            }
        }
        public void setB(){
            setBRecursive(root);
        }

    }

    public static void main(String[] args) {
        // write your code here
        new Thread(null, new Main(), "", 64 * 1024 * 1024).start();
    }
}
