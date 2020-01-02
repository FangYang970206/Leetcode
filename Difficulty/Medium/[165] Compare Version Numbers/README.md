# 问题描述

比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。

 . 字符不代表小数点，而是用于分隔数字序列。

例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。

你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
 

示例 1:

```bash
输入: version1 = "0.1", version2 = "1.1"
输出: -1
```

示例 2:

```bash
输入: version1 = "1.0.1", version2 = "1"
输出: 1
```

示例 3:

```bash
输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
```

示例 4：

```bash
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
```

示例 5：

```bash
输入：version1 = "1.0", version2 = "1.0.0"
输出：0
解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
```

# 方法

这一题挺无聊的，思路挺好想，但写出来很多bug，耗时很多。。。看了discuss，推荐更加更好的思路：
C++:
```c++
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}

int compareVersion(string version1, string version2) {
    for(auto& w : version1) if (w == '.') w=' ';
    for(auto& w : version2) if (w == '.') w=' ';
    istringstream s1(version1), s2(version2);
    while(1) {
        int n1,n2;
        if (not(s1 >> n1) ) n1 = 0;
        if (not(s2 >> n2) ) n2 = 0;
        if (not s1 and not s2) return 0;
        if (n1<n2) return -1;
        if (n1>n2) return 1;
    }
}
```

python3:

```python
def compareVersion(self, version1, version2):
        versions1 = [int(v) for v in version1.split(".")]
        versions2 = [int(v) for v in version2.split(".")]
        for i in range(max(len(versions1),len(versions2))):
            v1 = versions1[i] if i < len(versions1) else 0
            v2 = versions2[i] if i < len(versions2) else 0
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1;
        return 0;
```