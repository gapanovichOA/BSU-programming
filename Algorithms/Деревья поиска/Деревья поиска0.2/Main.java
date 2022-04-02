import java.io.*;
import java.util.Scanner;

//По набору ключей постройте бинарное поисковое дерево. Удалите из него ключ (правым удалением), если он есть в дереве.
// Выполните прямой левый обход полученного дерева.
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
            int value = sc.nextInt();
            while (sc.hasNext()) {
                tree.add(sc.nextInt());
            }
            tree.delete(value);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
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

            Node(int value) {
                this.value = value;
                right = null;
                left = null;
            }
        }

        Node root;
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
                writer.println(node.value);
                traversePreOrderRecursive(node.left);
                traversePreOrderRecursive(node.right);
            }
        }

        public void traversePreOrder() {
            traversePreOrderRecursive(root);
            writer.close();
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
            root = deleteRecursive(root, value);
        }

    }

    public static void main(String[] args) {
        // write your code here
        new Thread(null, new Main(), "", 64 * 1024 * 1024).start();
    }
}
