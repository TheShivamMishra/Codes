/**
 * a
 */
public class a {

    public static void main(String[] args) {
        int []arr = { 2, 3, 5, 7 };
        boolean vis[] = new boolean[4];
        System.out.println(coinChangePermu_01(arr, 10, vis, " "));
    }

    public static int coinChangePermu_01(int[] arr, int tar, boolean[] vis, String ans) {
        if (tar == 0) {
            System.out.println(ans);
            return 1;
        }

        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (!vis[i] && tar - arr[i] >= 0) {
                vis[i] = true;
                count += coinChangePermu_01(arr, tar - arr[i], vis, ans + arr[i] + " ");
                vis[i] = false;
            }
        }
        return count;
    }

}