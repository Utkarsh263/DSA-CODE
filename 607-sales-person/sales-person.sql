# Write your MySQL query statement below
SELECT name from 
SalesPerson where 
sales_id not in(

    Select sales_id 
    from orders o 
    join company c 
    on o.com_id = c.com_id
    where c.name = 'RED'
)