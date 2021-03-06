# 48. 旋转图像
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
要求空间复杂度O(1)

![图像旋转](./mat2.jpg)

## 分析
通过找规律的方式能够得到旋转前后元素之间的映射关系，但是严格来说这是一道几何题，主要考察了**空间变换**的知识。

图像旋转的效果如图1所示

![图1](./1.png)

其旋转过程其实包括了两部分，第一步绕原点顺时针旋转``90°``，第二步沿原y轴右移``n - 1``
![图2](./2.png)

这两步的变换矩阵可以写出来
```
 0   1   0
-1   0  n-1
 0   0   1
```

进一步可以得到坐标变换公式，代表原始位置的坐标变换后的新坐标
```
new_x = ori_y
new_y = n - 1 - ori_x
```
反向可以推出任意位置的新坐标是由哪一原始坐标得到的(方便写代码)
```
ori_x = n - new_y - 1
ori_y = new_x
```
于是我们通过坐标变换的方式得到了公式

## 代码
时间复杂度：O(n^2)
空间复杂度：O(1)
```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 1) return;

        for(int i = 0; i < n / 2; ++i){
            for(int j = i; j < n - i - 1; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
        return;
    }
};
```