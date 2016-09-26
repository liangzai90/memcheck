mtrace
=======

1. Description
--------
- As we known, mtrace �ܹ����malloc��free��ԣ���malloc��free����ԣ���������Ϊ�ڴ�й¶;����ȱ���ǲ��ܼ��new/new[]��delete/delete[]��Ե�����, ׼ȷ˵�ǿ��Լ�鴦�����ڴ�й¶�����ǲ���ָ���ĸ�λ��й¶�ˡ�
- memtrace.h �ֲ�mtrace�Ĳ��㣨�����������ܼ��new��delete������⣬�����޷����malloc��free������⡣
- ���mtrace �� memtrace.h���ԱȽ�ȫ��Ľ����ڴ�й¶��⡣


2. mtrace
-----
- mtrace usage
    - mtraceҪ��������ǰ���û�������`MALLOC_TRACE`
        
            export MALLOC_TRACE=trace.log

    - Ҫ�������-gѡ��

            g++ -g main.cpp -o main

    - ����
        
            ./main

    - �ڵ�ǰĿ¼������`trace.log`�ļ�
    - ʹ��mtrace�������trace.log

            mtrace main trace.log


- Result

    yangluo@yangluoPC:~/github/memcheck/testcase/mtrace$ mtrace main trace.log 
    
    Memory not freed:
    -----------------
               Address     Size     Caller
               0x0000000000f06460      0x8  at /home/yangluo/github/memcheck/testcase/mtrace/main.cpp:40
               0x0000000000f06480      0x3  at /home/yangluo/github/memcheck/testcase/mtrace/main.cpp:68
    

3. memtrace.h
------
- Usage
         
        g++ -g testMemtrace.cpp -o test
        ./test
        vi trace.report

- Decription
    - memtrace.h �ܹ���ɶ�new�ڴ�й¶�ļ�⣬�����ܼ��malloc��malloc�Ĺ�������mtrace.
    - Ӧ�ó���(testMemtrace.cpp)�����memtrace.hͷ�ļ���


4. BUG
------
- ���cpp�ļ�����memtrace.hʱ�ᱨ�ض������#ifndef������ˣ��������
- �����so����������д�����Ч��

5. BUG -> Solution
------
- ����ʵ�ֲ�Ӧ��д��ͷ�ļ��У�����ͬcpp�ļ�������ͷ�ļ�֮�󣬸��Ա����obj����Ȼ�ᵼ�³嶨�塣����취������ȡ����ʵ�ֲ���Ϊ.cpp(memtrace.cpp)��ͷ�ļ�ֻ��©�ӿڡ�����.cpp�ļ���̶�̬�⣬����ʹ�á�


6. Solution -> Usage
------
- ���붯̬��

        g++ -shared -fPIC memtrace.cpp -o libtrace.so
        cp libtrace.so /lib


- Ӧ��

        g++ main.cpp maintain.cpp util.cpp -o main -ltrace

- ���
        # head trace.report 

        Note: This file only records memory details which is alloced by "new" but never "delete"

        File                  Line        Function                        Size      

        main.cpp              29          foo                             1         
        util.cpp              8           uoo                             4         
        maintain.cpp          8           moo                             4         

        
- ˵��
  Ӧ�ò������memtrace.h�ļ���
