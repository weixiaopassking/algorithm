/*
有一在不占用额外内存空间的情况下(即不使用缓存矩阵)，将矩阵顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，矩阵元素小于等于256。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]

思路：
1.先绕着左上角到右下角的对称轴做对称变换
2.绕着竖直方向的对称轴做对称变换
 */

class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(mat[i][j],mat[j][i]);
            }
        }

        int start=0;
        int end=mat[0].size()-1;
        while(start<end){
            for(int i=0;i<mat.size();++i){
                swap(mat[i][start],mat[i][end]);
            }
            start++;
            end--;
        }
        return mat;
    }
};
