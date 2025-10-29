# Write your MySQL query statement below
-- select e.employee_id 
-- from employees e 
-- left join employees m 
-- on e.manager_id = m. employee_id 
-- where e.manager_id IS NOT NULL
-- and m.employee_id IS NULL;

# Write your MySQL query statement below
SELECT employee_id FROM Employees
WHERE salary < 30000 AND manager_id IS NOT NULL 
    AND manager_id NOT IN (SELECT employee_id FROM Employees) 
ORDER BY employee_id;