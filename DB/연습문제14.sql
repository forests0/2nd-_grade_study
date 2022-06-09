CREATE TABLE Dept (
    deptno number(2),
    dname varchar2(14),
    loc varchar2(13),
    primary key(DEPTNO)
);

CREATE TABLE Emp(
    empno number(3),
    ename varchar2(10),
    job varchar2(9),
    mgr number(4),
    hiredate date,
    sal number(7.2),
    domm number(7.2),
    deptno number(2),
    primary key(empno)
);


INSERT INTO EMP VALUES (7369, 'SMITH', 'CLERK', 7902,TO_DATE('1980-12-17', 'YYYY-MM-DD'), 800, NULL, 20);
INSERT INTO EMP VALUES (7499, 'ALLEN', 'SALESMAN', 7698,TO_DATE('1981-02-20', 'YYYY-MM-DD'), 1600, 300, 30);
INSERT INTO EMP VALUES (7521, 'WARD', 'SALESMAN', 7698,TO_DATE('1981-02-22', 'YYYY-MM-DD'), 1250, 500, 30);
INSERT INTO EMP VALUES (7566, 'JONES', 'MANAGER', 7839,TO_DATE('1981-04-02', 'YYYY-MM-DD'), 2975, NULL, 20);
INSERT INTO EMP VALUES (7654, 'MARTIN', 'SALESMAN', 7698,TO_DATE('1981-09-28', 'YYYY-MM-DD'), 1250, 1400, 30);
INSERT INTO EMP VALUES (7698, 'BLAKE', 'MANAGER', 7839,TO_DATE('1981-05-01', 'YYYY-MM-DD'), 2850, NULL, 30);
INSERT INTO EMP VALUES (7782, 'CLARK', 'MANAGER', 7839,TO_DATE('1981-06-09', 'YYYY-MM-DD'), 2450, NULL, 10);
INSERT INTO EMP VALUES (7788, 'SCOTT', 'ANALYST', 7566,TO_DATE('1982-12-09', 'YYYY-MM-DD'), 3000, NULL, 20);
INSERT INTO EMP VALUES (7839, 'KING', 'PRESIDENT', NULL,TO_DATE('1981-11-17', 'YYYY-MM-DD'), 5000, NULL, 10);
INSERT INTO EMP VALUES (7844, 'TURNER', 'SALESMAN', 7698,TO_DATE('1981-09-08', 'YYYY-MM-DD'), 1500, 0, 30);
INSERT INTO EMP VALUES (7876, 'ADAMS', 'CLERK', 7788,TO_DATE('1983-01-12', 'YYYY-MM-DD'), 1100, NULL, 20);
INSERT INTO EMP VALUES (7900, 'JAMES', 'CLERK', 7698,TO_DATE('1981-12-03', 'YYYY-MM-DD'), 950, NULL, 30);
INSERT INTO EMP VALUES (7902, 'FORD', 'ANALYST', 7566,TO_DATE('1981-12-03', 'YYYY-MM-DD'), 3000, NULL, 20);
INSERT INTO EMP VALUES (7934, 'MILLER', 'CLERK', 7782,TO_DATE('1982-01-23', 'YYYY-MM-DD'), 1300, NULL, 10);

INSERT INTO DEPT VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO DEPT VALUES (20, 'RESEARCH', 'DALLAS');
INSERT INTO DEPT VALUES (30, 'SALES', 'CHICAGO');
INSERT INTO DEPT VALUES (40, 'OPERATIONS', 'BOSTON');

SELECT
    ename as 사원이름,
    job as 사원업무
FROM emp;

SELECT
    emp.ename,
    emp.sal
FROM emp
WHERE deptno = 30;

SELECT
    empno,
    ename,
    sal,
    comm 증가액,
    sal + (sal / 10) 인상된_급여
FROM emp
ORDER BY empno;

SELECT
    ename,
    deptno
FROM emp
WHERE ename like 'S%';

SELECT
    MAX(sal) MAX,
    MIN(sal) MIN,
    SUM(sal) SUM,
    ROUND(AVG(sal)) AVG
FROM emp;

SELECT
    job 업무,
    COUNT(ename) 업무별_사원수
FROM emp
GROUP BY job;

SELECT
    MAX(sal) - MIN(sal)
FROM emp;

SELECT
    COUNT(empno),
    SUM(sal),
    AVG(sal)
FROM emp
GROUP BY deptno
HAVING deptno = 30;

SELECT
    deptno
FROM emp
GROUP BY deptno
HAVING AVG(sal) = (SELECT MAX(AVG(sal)) FROM emp GROUP BY deptno);

SELECT 
    job,
    avg(sal)
FROM emp
WHERE job != 'SALESMAN'
GROUP BY job
HAVING sum(sal) >= 3000
ORDER BY AVG(sal) DESC;

SELECT
    COUNT(*)
FROM emp
WHERE mgr IN (SELECT empno FROM emp);

SELECT
    ename,
    sal,
    comm,
    sal * 12 + comm
FROM emp
WHERE comm IS NOT NULL
ORDER BY sal * 12 + comm;

SELECT
    deptno,
    job,
    COUNT(*)
FROM emp
GROUP BY deptno, job;

SELECT
    dname
FROM dept
WHERE deptno NOT IN (SELECT deptno FROM emp GROUP BY deptno);

SELECT
    job,
    COUNT(*)
FROM emp
GROUP BY job
HAVING COUNT(*) >= 4;

SELECT
    ename
FROM emp
WHERE 7400 <= empno AND empno <= 7600;

SELECT
    emp.ename,
    dept.dname
FROM emp, dept
WHERE emp.deptno = dept.deptno;

SELECT
    e1.ename,
    e2.ename
FROM emp e1, emp e2
WHERE e1.mgr = e2.empno;

SELECT
    ename
FROM emp
WHERE sal > (SELECT sal FROM emp WHERE ename = 'SCOTT');

SELECT
    deptno
FROM dept
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'SCOTT') OR deptno = (SELECT deptno FROM dept WHERE loc = 'DALLAS');