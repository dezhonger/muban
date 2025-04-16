import sympy as sp

# 获取用户输入的模数，默认值为 3 5 7
input_str = input("请输入模数，用空格分隔（默认: 3 5 7）: ")
if input_str.strip() == "":
    moduli = [3, 5, 7]
else:
    moduli = [int(x) for x in input_str.split()]

remainders = sp.symbols(' '.join([f'r{i}' for i in range(len(moduli))]))

product = 1
for m in moduli:
    product *= m

result = 0
for i in range(len(moduli)):
    p = product // moduli[i]
    # 计算模逆元
    inverse = sp.mod_inverse(p, moduli[i])
    result += remainders[i] * inverse * p

solution = sp.simplify(result % product)
remainder_prompts = [f"模 {moduli[i]} 余 r{i}" for i in range(len(moduli))]
prompt_str = "、".join(remainder_prompts)
print(f"满足 {prompt_str} 的最小非负整数解的表达式是: {solution}")
    
