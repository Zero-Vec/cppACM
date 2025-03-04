def split_into_evens(number_str):
    result = []
    i = 0
    while i < len(number_str):
        # 如果是偶数，则单独作为一个偶数，包括0
        if int(number_str[i]) % 2 == 0:
            result.append(int(number_str[i]))
        # 如果是奇数，向后寻找下一个偶数并组合
        else:
            # 由于输入保证是偶数，所以奇数后面至少会存在一个字符
            j = i + 1
            while j < len(number_str) and int(number_str[j]) % 2 != 0:
                j += 1
            result.append(int(number_str[i:j+1]))  # 把找到的整个偶数放入结果
            i = j  # 移动到这个偶数的最后一个数字
        i += 1
    return result

# 示例输入
input_number_str = input()
# 执行拆分操作
even_numbers = split_into_evens(input_number_str)
even_numbers.sort();
# 打印结果
for even_number in even_numbers:
    print(even_number)