# Write your MySQL query statement below
SELECT 
    u.name,
    SUM(t.amount) AS BALANCE
    FROM USERS u
    JOIN TRANSACTIONS t
    on u.account = t.account
GROUP BY u.account
Having SUM(t.amount) > 10000;
