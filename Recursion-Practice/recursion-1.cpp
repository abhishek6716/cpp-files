/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// get substr /////////////////////////////////////////
/*
#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){

    if (s == ""){
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }

    char ch = s[0];
    string ros = s.substr(1);

    vector<string> rres = gss(ros);
    vector<string> mres;

    for (int i=0; i<rres.size(); i++){
        mres.push_back(rres[i]);
        ///mres.push_back(ch + rres[i]);
    }
    for (string s : rres){
        mres.push_back(ch + s);
    }
    return mres;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// get KPC //////////////////////////////////////////////
/*
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        ArrayList<String> words = getKPC(str);
        System.out.println(words);
    }

    static String[] codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
    
    public static ArrayList<String> getKPC(String str) {
        
        if(str.length() == 0){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }

        char ch = str.charAt(0);
        String ros = str.substring(1);

        ArrayList<String> rres = getKPC(ros);
        ArrayList<String> mres = new ArrayList<>();

        string codeforch=codes[ch-'0'];
        for(int i=0; i<codeforch.length(); i++){
            char chcode=codeforch.chAt(i);
            for(string rstr: rres){
                mres.add(chcode+rstr);
            }
        }
        return mres;
    }
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// get stair paths ////////////////////////////////////////
/*
    public static ArrayList<String> getStairPaths(int n) {
        if(n <= 0){
            ArrayList<String> bres = new ArrayList<>();

            if(n == 0){
                bres.add("");
            }

            return bres;
        }
    
        ArrayList<String> rres1 = getStairPaths(n - 1);
        ArrayList<String> rres2 = getStairPaths(n - 2);
        ArrayList<String> rres3 = getStairPaths(n - 3);
        ArrayList<String> mres = new ArrayList<>();

        for(String rstr: rres1){
            mres.add(1 + rstr);
        }

        for(String rstr: rres2){
            mres.add(2 + rstr);
        }

        for(String rstr: rres3){
            mres.add(3 + rstr);
        }

        return mres;
    }
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// get maze paths /////////////////////////////////////////
/*

/// way-1
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        ArrayList<String> paths = getMazePaths(0, 0, n - 1, m - 1);
        System.out.println(paths);
    }

    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
        if(sr > dr || sc > dc){
            return new ArrayList<>();
        }

        if(sr == dr && sc == dc){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }

        ArrayList<String> hpaths = getMazePaths(sr, sc + 1, dr, dc);
        ArrayList<String> vpaths = getMazePaths(sr + 1, sc, dr, dc);
        ArrayList<String> paths = new ArrayList<>();

        for(String hpath: hpaths){
            paths.add('h' + hpath);
        }

        for(String vpath: vpaths){
            paths.add('v' + vpath);
        }

        return paths;
    }
}

// way-2
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        ArrayList<String> paths = getMazePaths(1, 1, n, m);
        System.out.println(paths);
    }

    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
        if(sr == dr && sc == dc){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }

        ArrayList<String> hpaths = new ArrayList<>();
        ArrayList<String> vpaths = new ArrayList<>();
        if(sc<dc){
            hpaths = getMazePaths(sr, sc + 1, dr, dc);
        }
        if(sr<dr){
            vpaths = getMazePaths(sr+1, sc, dr, dc);
        }
        ArrayList<String> paths = new ArrayList<>();

        for(String hpath: hpaths){
            paths.add('h' + hpath);
        }

        for(String vpath: vpaths){
            paths.add('v' + vpath);
        }

        return paths;
    }
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// get maze paths with jumps //////////////////////////////
/*
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        ArrayList<String> paths = getMazePaths(0, 0, n - 1, m - 1);
        System.out.println(paths);
    }

    public static ArrayList<String> getMazePaths(int sr, int sc, int dr, int dc) {
        if(sr > dr || sc > dc){
            return new ArrayList<>();
        }

        if(sr == dr && sc == dc){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }

        ArrayList<String> paths = new ArrayList<>();
        for(int move = 1; move <= dc - sc; move++){
            ArrayList<String> hpaths = getMazePaths(sr, sc + move, dr, dc);
            for(String hpath: hpaths){
                paths.add("h" + move + hpath);
            }
        }
        
        for(int move = 1; move <= dr - sr; move++){
            ArrayList<String> vpaths = getMazePaths(sr + move, sc, dr, dc);
            for(String vpath: vpaths){
                paths.add("v" + move + vpath);
            }
        }

        for(int move = 1; move <= dc - sc && move <= dr - sr; move++){
            ArrayList<String> dpaths = getMazePaths(sr + move, sc + move, dr, dc);
            for(String dpath: dpaths){
                paths.add("d" + move + dpath);
            }
        }

        return paths;
    }
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print subsequence //////////////////////////////////////
/*
#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    if (ques.length() == 0){
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    printSS(roq, ans + ch);
    printSS(roq, ans + "");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print kpc //////////////////////////////////////////////
/*
#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    if (ques.length() == 0){
        cout << asf << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    
    string codeforch=codes[ch-'0'];
    for(int i=0; i<codeforch.length(); i++){
        ch cho=codeforch.charAt(i);
        printKPC(roq, ans+cho);
    }
}
int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// get stair paths ////////////////////////////////////////
/*
#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    if (n <= 0){
        if (n == 0){
            cout << psf << endl;
        }
        return;
    }

    printStairPaths(n - 1, psf + "1");
    printStairPaths(n - 2, psf + "2");
    printStairPaths(n - 3, psf + "3");
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print maze paths ///////////////////////////////////////
/*
#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr > dr || sc > dc){
        return;
    }

    if (sr == dr && sc == dc){
        cout << psf << endl;
        return;
    }

    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print maze paths with jumps //////////////////////////////
/*
#include<iostream>
using namespace std;

    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        if(sr > dr || sc > dc){
            return;
        }

        if(sr == dr && sc == dc){
            cout<<psf<<endl;
            return;
        }

        for(int jumps = 1; jumps <= dc - sc; jumps++){
            printMazePaths(sr, sc + jumps, dr, dc, psf + "h" + (to_string)(jumps));
        }

        for(int jumps = 1; jumps <= dr - sr; jumps++){
            printMazePaths(sr + jumps, sc, dr, dc, psf + "v" + (to_string)(jumps));
        }

        for(int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++){
            printMazePaths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (to_string)(jumps));
        }
        
    }
int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print permutations ///////////////////////////////////////
/*
#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }

    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        printPermutations(ros,asf + ch);
    }

}
int main(){
    string str;
    cin>>str;
    printPermutations(str,"");  
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// print encodings //////////////////////////////////////////
/*
#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(str[0] == '0'){
        return;
    }

    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));

    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }

}
int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// flood fill ///////////////////////////////////////////////
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

      floodfill(arr, 0, 0, "", new boolean[n][m]);  
   }

   public static void floodfill(int[][] maze, int row, int col, String psf, boolean[][] visited){
      if(row < 0 || col < 0 || row >= maze.length || col >= maze[0].length || 
         maze[row][col] == 1 || visited[row][col] == true){
         return;
      } else if(row == maze.length - 1 && col == maze[0].length - 1){
         System.out.println(psf);
         return;
      }

      visited[row][col] = true;
      floodfill(maze, row - 1, col, psf + "t", visited);
      floodfill(maze, row, col - 1, psf + "l", visited);
      floodfill(maze, row + 1, col, psf + "d", visited);
      floodfill(maze, row, col + 1, psf + "r", visited);
      visited[row][col] = false;
   }

}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// target sum subsets ///////////////////////////////////////
/*
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
    
        for(int i = 0; i < n; i++){
           arr[i] = Integer.parseInt(br.readLine());
        }

        int tar = Integer.parseInt(br.readLine());
        printTargetSumSubsets(arr, 0, "", 0, tar);
    }

    // set is the subset
    // sos is sum of subset
    // tar is target
    public static void printTargetSumSubsets(int[] arr, int idx, String set, int sos, int tar) {
        if(sos > tar){
            return;
        }

        if(idx == arr.length){
            if(sos == tar){
                System.out.println(set + ".");
            }
            return;
        }

        printTargetSumSubsets(arr, idx + 1, set + arr[idx] + ", ", sos + arr[idx], tar);
        printTargetSumSubsets(arr, idx + 1, set, sos, tar);
    }

}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// N-queens /////////////////////////////////////////////////
/*
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] chess = new int[n][n];
        printNQueens(chess, "", 0);
    }

    public static void printNQueens(int[][] chess, String qsf, int row){
        if(row == chess.length){
            System.out.println(qsf + ".");
            return;
        }
        for(int col = 0; col < chess.length; col++){
            if(chess[row][col] == 0 && isQueenSafe(chess, row, col) == true){
                chess[row][col] = 1;
                printNQueens(chess, qsf + row + "-" + col + ", ", row + 1);
                chess[row][col] = 0;
            }
        }
    }

    public static boolean isQueenSafe(int[][] chess, int row, int col){
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col; i >= 0; i--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < chess.length; i--, j++){
            if(chess[i][j] == 1){
                return false;
            }
        }

        for(int i = row, j = col - 1; j >= 0; j--){
            if(chess[i][j] == 1){
                return false;
            }
        }

        return true;
    }
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// knight tour //////////////////////////////////////////////
/*
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int r = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());

        int[][] chess = new int[n][n];
        printKnightsTour(chess, r, c, 1);
    }

    public static void printKnightsTour(int[][] chess, int r, int c, int upcomingMove){
        if(r < 0 || c < 0 || r >= chess.length || c >= chess.length || chess[r][c] != 0){
            return;
        } else if(upcomingMove == chess.length * chess.length){
            chess[r][c] = upcomingMove;
            displayBoard(chess);
            chess[r][c] = 0;    
            return;
        }

        chess[r][c] = upcomingMove;
        printKnightsTour(chess, r - 2, c + 1, upcomingMove + 1);
        printKnightsTour(chess, r - 1, c + 2 , upcomingMove + 1);
        printKnightsTour(chess, r + 1, c + 2 , upcomingMove + 1);
        printKnightsTour(chess, r + 2, c + 1 , upcomingMove + 1);
        printKnightsTour(chess, r + 2, c - 1 , upcomingMove + 1);
        printKnightsTour(chess, r + 1, c - 2 , upcomingMove + 1);
        printKnightsTour(chess, r - 1, c - 2 , upcomingMove + 1);
        printKnightsTour(chess, r - 2, c - 1 , upcomingMove + 1);
        chess[r][c] = 0;
    }

    public static void displayBoard(int[][] chess){
        for(int i = 0; i < chess.length; i++){
            for(int j = 0; j < chess[0].length; j++){
                System.out.print(chess[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println();
    }
}
*/

