class Solution
{
public:
    //W.N.E.S
    //     vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {

    //         int n = image.size();
    //         int m = image[0].size();
    //         DFS_helper(image, i, j, n, m, image[i][j], newColor);
    //         return image;
    //     }
    //     void DFS_helper(vector<vector<int>>& image, int i, int j, int n, int m, int target, int newColor){
    //         if(i<0||j<0||i>=n||j>=m||image[i][j]!=target||image[i][j]==newColor){
    //             return;
    //         }
    //         image[i][j] = newColor;
    //         int dx[] = {-1, 0, 1, 0};
    //         int dy[] = {0, -1, 0, 1};
    //         for(int k=0;k<4;k++){
    //             DFS_helper(image, i+dx[k], j+dy[k], n, m, target, newColor);
    //         }
    //     }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int i, int j, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        DFS(image, i, j, n, m, image[i][j], newColor);
        return image;
    }
    void DFS(vector<vector<int>> &image, int i, int j, int n, int m, int currentColor, int newColor)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != currentColor || image[i][j] == newColor)
        {
            return;
        }
        image[i][j] = newColor;
        int moveX[] = {-1, 0, 1, 0};
        int moveY[] = {0, -1, 0, 1};
        for (int a = 0; a < 4; a++)
        {
            DFS(image, i + moveX[a], j + moveY[a], n, m, currentColor, newColor);
        }
    }
};