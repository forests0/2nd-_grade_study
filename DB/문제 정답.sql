
/*고객(기업)의 모든 튜플 수를 출력 */
SELECT COUNT(*) AS Total_Row FROM customers; 

/*고객(기업)의 이름이 Apple인 회사의 웹사이트 주소 출력 */
SELECT website FROM customers
WHERE customers.name = 'Apple';

/*고객(기업)의 이름이 Apple 또는 Oracle 또는 eBay인
회사의 웹사이트 주소 출력*/
SELECT website FROM customers
WHERE name = 'Apple' OR name = 'eBay' OR name = 'Oracle';

/*고객(기업)의 신용평가가 높은 순으로 기업명과
신용평가를 출력 */
SELECT name, credit_limit FROM customers
ORDER BY credit_limit DESC;

/*고객(기업)의 주소가 Bangalore (방갈로르)에
위치한 기업의 이름과 주소를 출력*/
SELECT name, address FROM customers
WHERE address LIKE '%Bangalore%';

/*직원의 모든 역할을 중복없이 출력
(group by 사용 X)*/
SELECT DISTINCT job_title FROM employees;

/*직원 모든 직업 개수를 출력(중복 제거)
(group by 사용 X)*/
SELECT count(DISTINCT job_title)AS result FROM employees;

/*직원의 역할이 Programmer인
사람의 이름과 직업명을 출력*/
SELECT first_name, job_title FROM employees
WHERE job_title = 'Programmer';

/*주문물품목록에서 각 주문당 주문 제품 개수와 가격을 출력
(묶음 배송은 하나로 간주)
(주문 개수가 높은 순으로 정렬하되 같은 값이 있다면 주문 가격이 높은 순으로 출력)*/
SELECT SUM(quantity) AS total_sum, SUM(quantity * unit_price) AS total_price
FROM order_items
GROUP BY order_id
ORDER BY total_sum DESC, total_price DESC;

/*직원 중 상급자가 없는 직원의 이름과 역할을 출력*/
SELECT first_name, job_title FROM employees
WHERE manager_id is null;

/*부속질의문을 사용하여 Mohammad 직원의
모든 부하직원 이름을 출력*/
SELECT first_name FROM employees
WHERE manager_id = (
SELECT employee_id FROM employees
WHERE first_name = 'Mohammad');

/*부속질의문을 사용하여 Tommy 직원의
부하직원 중 직업명이 Sales Manager 또는 Stock Manager인
사람의 이름과 역할을 출력 */
SELECT first_name, job_title FROM employees
WHERE manager_id = (
SELECT employee_id FROM employees
WHERE first_name = 'Tommy') AND job_title = 'Sales Manager' OR job_title = 'Stock Manager';

