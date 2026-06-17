# Write your MySQL query statement below
SELECT v.customer_id , COUNT(*) as count_no_trans
From Visits v 
LEFT JOIN 
Transactions t 
on v.visit_id = t.visit_id 
where t.visit_id is null 
Group by v.customer_id;