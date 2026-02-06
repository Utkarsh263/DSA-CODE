# Write your MySQL query statement below

Select name from SalesPerson 
where sales_id not in(
    SELECT o.sales_id from company c
    join orders o
    on c.com_id = o.com_id
    where c.name = 'RED'
)