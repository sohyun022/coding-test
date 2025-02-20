-- 코드를 입력하세요
SELECT F.FLAVOR
FROM FIRST_HALF F join ICECREAM_INFO I
on F.flavor = I.flavor
where F.total_order > 3000 and I.INGREDIENT_TYPE ='fruit_based'
ORDER BY F.total_order desc