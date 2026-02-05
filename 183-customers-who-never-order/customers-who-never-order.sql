# Write your MySQL query statement below
SELECT c.name as Customers 
from customers c
left join orders o
on c.id = o.customerId
where o.customerID IS NULL;