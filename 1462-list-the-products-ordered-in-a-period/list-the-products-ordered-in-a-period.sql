# Write your MySQL query statement below
SELECT 
    p.product_name,
    SUM(o.unit) as Unit
FROM Products p
Join Orders o
on p.product_id = o.product_id
WHERE o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p.product_id
HAVING SUM(o.unit) >= 100
ORDER BY p.product_name;