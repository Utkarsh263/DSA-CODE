# Write your MySQL query statement below
SELECT p.project_id ,
       ROUND(AVG(e.experience_years) , 2) as average_years
FROM Project p
Join 
Employee e
on p.employee_id = e.employee_id
group by project_id;