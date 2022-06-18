select abs(-15) from dual; --절대값
select ceil(15.7) from dual; --올림
select power(3,2) from dual; --3^2 (첫번째 수가 m, 두번째 수가 n이라면 m^n)
select round(15.2) from dual; --반올림
select concat('Happy','Birthday') from dual; --문자열 2개 이어붙이기
select lower('Birthday') from dual; --소문자 변환
select lpad('Page 1', 15, '*.') from dual; --왼쪽에서부터 지정한 길이만큼 지정한 문자로 채우기
select ltrim('Page 1','ae') from dual; --왼쪽에서부터 특정 문자열 제거(현재는 ae가 없어서 공백제거가 됨)
select replace('Jack', 'J', 'BK') from dual; --특정 문자를 바꾸기
select substr('ABCDEFG', 3,4) from dual; --특정 위치부터 지정한 위치까지 문자 반환
select ascii('A') from dual; --아스키코드 숫자 반환
select instr('CORPORATE FLOOR', 'OR', 3,2) from dual; --특정 문자를 찾아서 그 위치를 반환, 뒤에 숫자는 검사할 위치, 그 뒤에 숫자는 몇번째 찾은 위치를 반환
select sysdate from dual; --오늘 날짜 반환
select nullif(123,345) from dual; --둘이 같다면 null을, 아니면 앞에 값을 반환
select nvl(null,123) from dual; --1번값이 null이라면 2번값을 반환, 아니면 1번값을 반환
