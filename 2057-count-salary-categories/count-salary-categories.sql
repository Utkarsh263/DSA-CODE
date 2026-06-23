# Write your MySQL query statement below
SELECT 'Low Salary' as category, 
        COUNT(*) as accounts_count 
FROM Accounts 
WHERE income < 20000

UNION ALL 

SELECT 'Average Salary' as category , 
COUNT(*) AS accounts_count
FROM Accounts 
where income BETWEEN 20000 AND 50000

UNION ALL 

SELECT 'High Salary' as category, 
COUNT(*) AS account_count
FROM Accounts 
where income > 50000