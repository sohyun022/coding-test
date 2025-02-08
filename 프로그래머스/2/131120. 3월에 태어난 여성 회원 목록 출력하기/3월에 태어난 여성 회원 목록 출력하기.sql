-- 코드를 입력하세요
SELECT MEMBER_ID,MEMBER_NAME,GENDER,DATE_FORMAT(DATE_OF_BIRTH,'%Y-%m-%d')
FROM MEMBER_PROFILE
WHERE GENDER='W' and TLNO is not null and MONTH(DATE_OF_BIRTH) = 3
ORDER BY MEMBER_ID ASC;