///////////////////////////////////////////////////////////
///////////////////////// fibo ////////////////////////////
/*
int fib(int n){
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
*/


/////////////////////////////////////////////////////////////////
/////////////////// climbing stairs /////////////////////////////
/*
int cs(int n){
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if(i >= 2){
            dp[i] += dp[i - 2];
        }
        if(i >= 3){
            dp[i] += dp[i - 3];
        }
    }
    return dp[n];

}
int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
*/

//////////////////////////////////////////////////////////////////////////
//////////////////// Climb Stairs With Variable Jumps ////////////////////
/*
int cs(int arr[], int n){
    int dp[n + 1];
    for(int i = 0 ; i <= n; i++){
        dp[i] = 0;
    }
    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        for(int jumps = 1; jumps <= arr[i]; jumps++){
            if(i + jumps <= n){
                dp[i] += dp[i + jumps];
            }
        }
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
*/

///////////////////////////////////////////////////////////////////////
//////////////////// Climb Stairs With Minimum Moves //////////////////
/*
public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int[] arr = new int[n];
      for (int i = 0; i < arr.length; i++) {
         arr[i] = Integer.parseInt(br.readLine());
      }

      Integer[] dp = new Integer[n + 1];
      dp[n] = 0;

      for (int i = n - 1; i >= 0; i--) {
         if (arr[i] > 0) {
            int min = Integer.MAX_VALUE;

            for (int j = 1; j <= arr[i] && i + j < dp.length; j++) {
               if(dp[i + j] != null){
                  min = Math.min(min, dp[i + j]);
               }
            }

            if(min != Integer.MAX_VALUE){
               dp[i] = min + 1;
            }
         }
      }

      System.out.println(dp[0]);
   }
}
*/

////////////////////////////////////////////////////////////////////////
//////////////////////// Min Cost In Maze Traversal ////////////////////
/*
public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int m = Integer.parseInt(br.readLine());
      int[][] arr = new int[n][m];

      for (int i = 0; i < n; i++) {
         String str = br.readLine();
         for (int j = 0; j < m; j++) {
            arr[i][j] = Integer.parseInt(str.split(" ")[j]);
         }
      }

      int[][] dp = new int[arr.length][arr[0].length];
      for(int i = arr.length - 1; i >= 0; i--){
         for(int j = arr[0].length - 1; j >= 0; j--){
            if(i == arr.length - 1 && j == arr[0].length - 1){
               dp[i][j] = arr[i][j];
            } else if(i == arr.length - 1){
               dp[i][j] = arr[i][j] + dp[i][j + 1];
            } else if(j == arr[0].length - 1){
               dp[i][j] = arr[i][j] + dp[i + 1][j];
            } else {
               dp[i][j] = arr[i][j] + Math.min(dp[i][j + 1], dp[i + 1][j]);
            }
         }
      }

      System.out.println(dp[0][0]);
   }

}
*/

////////////////////////////////////////////////////////////////////////
/////////////////////////////// goldmine ///////////////////////////////
/*
public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int m = Integer.parseInt(br.readLine());
      int[][] arr = new int[n][m];

      for (int i = 0; i < n; i++) {
         String str = br.readLine();
         for (int j = 0; j < m; j++) {
            arr[i][j] = Integer.parseInt(str.split(" ")[j]);
         }
      }

      int[][] dp = new int[arr.length][arr[0].length];
      for (int j = arr[0].length - 1; j >= 0; j--) {
         for (int i = arr.length - 1; i >= 0; i--) {
            if (j == arr[0].length - 1) {
               dp[i][j] = arr[i][j];
            } else if (i == arr.length - 1) {
               dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], dp[i - 1][j + 1]);
            } else if (i == 0) {
               dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], dp[i + 1][j + 1]);
            } else {
               dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], Math.max(dp[i + 1][j + 1], dp[i - 1][j + 1]));
            }
         }
      }

      int max = dp[0][0];
      for (int i = 1; i < dp.length; i++) {
         max = Math.max(max, dp[i][0]);
      }
      System.out.println(max);
   }
}
*/

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Target Sum Subsets - Dp ///////////////////////////////
/*
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int tar = Integer.parseInt(br.readLine());

        boolean[][] dp = new boolean[arr.length + 1][tar + 1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    dp[i][j] = true;
                } else {
                    if(dp[i - 1][j] == true){
                        dp[i][j] = true;
                    } else {
                        int val = arr[i - 1];
                        if (j >= val && dp[i - 1][j - val] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }

        System.out.println(dp[dp.length - 1][tar]);
    }
}
*/

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Target Sum Subsets - Dp ///////////////////////////////
/*

*/