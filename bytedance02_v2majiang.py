import sys
import copy

def if_ok(a):
    # 排序
    a=sorted(a)
    print('一手好牌', a)
    # 序列a统计每一个元素出现的次数
    double=[] # 找所有的对子
    for i in set(a):
        if a.count(i)>=2:
            double.append(i)
    print("可当作雀头的牌", double)
    if len(double) == 0:
        print("无雀头，和牌失败")
        return False
    

    a1=a.copy()
    a2=[] # 记录和牌结果
    for i in double:
        print("double", i)
        a1.remove(i)
        a1.remove(i)
        a2.append((i, i))
        print(a1)
        for i in range(int(len(a1)/3)): #遍历剩下的几副顺子和刻字
            print("i-", i)
            if a1.count(a1[0] == 3):
                a2.append(a1[0], *3)
                a1=a1[3:]
                print(a1)
                
            elif a1[0] in a1 and a1[0]+1 in a1 and a1[0]+2 in a1:
                a2.append((a1[0], a1[0]+1, a1[0]+2))
                a1.remove(a1[0]+2)
                a1.remove(a1[0]+1)
                a1.remove(a1[0])
                print(a1)
            else:
                a1=a.copy()
                a2=[]
                print("重新寻找雀头")
                break;
        else:
            print("和牌成功：", a2)
            return True
    else:
        return False


a=list(map(int, sys.stdin.readline().split()))
ans=[]
for i in range(1, 10): #1-9
    b=copy.deepcopy(a)
    if b.count(i) < 4:
        b.append(i) # 自摸任意一个小于4的牌
        if(if_ok(b)):
            ans.append(str(i))

if ans==[]:
    print(0)
else:
    print(" ".join(ans))



