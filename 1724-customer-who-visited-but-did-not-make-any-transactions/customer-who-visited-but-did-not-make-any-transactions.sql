# Write your MySQL query statement below
SELECT v.customer_id , count(*) as count_no_trans
from Visits v 
Left Join 
Transactions t 
on t.visit_id = v.visit_id
where t.transaction_id is NULL
group by v.customer_id;