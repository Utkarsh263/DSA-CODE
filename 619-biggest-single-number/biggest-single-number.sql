# Write your MySQL query statement below
SELECT MAX(num) as num from(
    SELECT num from MyNumbers
    group by num
    having COUNT(num) =1)t;