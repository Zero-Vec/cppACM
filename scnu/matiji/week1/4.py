from collections import defaultdict

def is_match(opening, closing):
    return (opening == '(' and closing == ')') or \
           (opening == '[' and closing == ']') or \
           (opening == '{' and closing == '}')

def dfs(u, parent, s, tree, stack, res):
    # 在遍历过程中使用栈来记录当前路径的括号状态
    for v in tree[u]:
        if v == parent:
            continue
        # 当前子节点的符号
        char = s[v-1]

        # 判断当前符号是否可以和栈顶符号匹配
        if stack and is_match(stack[-1], char):
            stack.pop()
            res[0] += 1
        else:
            stack.append(char)

        # 继续深度优先搜索遍历子节点
        dfs(v, u, s, tree, stack, res)

        # 回溯，恢复栈的状态
        if stack and is_match(stack[-1], char):
            stack.pop()
        else:
            stack.append(char)

def count_balanced_paths(n, s, edges):
    tree = defaultdict(list)

    # 建立树的邻接表
    for u, v in edges:
        tree[u].append(v)
        tree[v].append(u)

    result = [0]  # 使用列表来保存结果
    stack = []    # 栈，用来检查路径的平衡情况
    dfs(1, -1, s, tree, stack, result)

    return result[0]

# 输入处理
n = int(input())
s = input().strip()
edges = [tuple(map(int, input().split())) for _ in range(n - 1)]

# 计算结果
print(count_balanced_paths(n, s, edges))
