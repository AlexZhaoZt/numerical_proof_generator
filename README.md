# numerical_proof_generator
数 字 论 证 生成器

这么臭的代码有什么写的必要吗

用逆波兰式往int array里填充0-4的数字（特例：-1，代表-1，仅在array的第一个元素使用），然后灌进stack里并进行计算，如果匹配就转换成逆波兰式输出。

目前还有不少bug（比如-1在逆波兰式中显示不正确）。

TODO: 把逆波兰转换成常规式子；加入幂运算；允许用户自己输入要论证的数（而不是在代码里修改）。

//main.cpp里有好多垃圾代码...请无视。
