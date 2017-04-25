import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    private static class MyClass {
        public long data;
        public int index;
        public MyClass(long data, int index) {
            this.data = data;
            this.index = index;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int x=sc.nextInt();
        long[] a=new long[n+5];
        for(int i=0;i<n;i++)
            a[i]=sc.nextLong();
        TreeSet<MyClass> ts = new TreeSet<>(new Comparator<MyClass>() {
            @Override
            public int compare(MyClass o1, MyClass o2) {
                long l=Math.abs(o1.data)-Math.abs(o2.data);
                if(l>0)
                    return 1;
                else if(l<0)
                    return -1;
                else
                    return o1.index-o2.index;
            }
        });
        int minus=0;
        for (int i = 0; i < n; i++) {
            ts.add(new MyClass(a[i], i));
            if(a[i]<0)
                minus++;
        }
        while(k>0) {
            if((minus&1) == 0) { //偶数个负数
                MyClass c1 = ts.ceiling(new MyClass(0, 1));
                if(c1.data==0) {
                    int id=c1.index;
                    a[id]-=x;
                    minus++;
                    ts.remove(c1);
                    ts.add(new MyClass(a[id], id));
                }
                else { //没有0
                    c1 = ts.first();
                    int id = c1.index;
                    if(a[id]<0) {
                        a[id]+=x;
                        if(a[id]>=0)
                            minus--;
                    }
                    else {
                        a[id]-=x;
                        if(a[id]<0)
                            minus++;
                    }
                    ts.remove(c1);
                    ts.add(new MyClass(a[id], id));
                }
            }
            else {
                MyClass c1 = ts.ceiling(new MyClass(0, 1));
                if(c1.data==0) {
                    int id=c1.index;
                    a[id]+=x;
                    ts.remove(c1);
                    ts.add(new MyClass(a[id], id));
                }
                else {
                    c1 = ts.first();
                    int id = c1.index;
                    if(a[id]<0)
                        a[id]-=x;
                    else
                        a[id]+=x;
                    ts.remove(c1);
                    ts.add(new MyClass(a[id], id));
                }
            }
            k--;
        }
        for(int i=0;i<n-1;i++) {
            System.out.print(a[i]+" ");
        }
        System.out.println(a[n-1]);
    }
}
