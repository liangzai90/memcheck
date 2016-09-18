mtrace
=======

1. Description
--------
- As we known, mtrace �ܹ����malloc��free��Ե����⣬��malloc��free����ԣ���ᵼ���ڴ�й¶;����ȱ���ǲ��ܼ��new/new[]��delete/delete[]��Ե����⡣
- �˲����������ڼ���ͨ����дnew/new[]�������ܷ���mtrace��������㡣


2. Usage
-----
- mtrace�÷�
    - mtraceҪ��������ǰ���û�������`MALLOC_TRACE`
        
        export MALLOC_TRACE=trace.log

    - Ҫ��-gѡ��

        g++ -g main.cpp -o main

    - ����
        
        ./main

    - �ڵ�ǰĿ¼������`trace.log`�ļ�
    - ʹ��mtrace ����trace.log

        mtrace main trace.log


3. Result
-----

    yangluo@yangluoPC:~/github/memcheck/testcase/mtrace$ mtrace main trace.log 
    
    Memory not freed:
    -----------------
               Address     Size     Caller
               0x0000000000f06460      0x8  at /home/yangluo/github/memcheck/testcase/mtrace/main.cpp:40
               0x0000000000f06480      0x3  at /home/yangluo/github/memcheck/testcase/mtrace/main.cpp:68
    

4. Conclustion
------
- ��дnew������֮��mtraceȷʵ�ܹ���鵽malloc�����ڴ��λ��
- �ӽ��������mallocʼ��λ��operator new �������ڣ� ��˵������������岻��


5. More
----
- ���Ի�ȡoperator new�ĵ�����, ʹ��gcc�ڽ�����__builtin_return_addr.
