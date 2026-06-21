# Write your MySQL query statement below
 
--  WE can use join and Row number both to solve 

-- DELETE p1 
-- FROM Person p1 
-- JOIN 
-- Person p2 
-- on p1.email = p2.email 
-- where p1.id > p2.id;

-- Using ROW_NUMBER

DELETE FROM PERSON 
WHERE id IN (
    SELECT id 
    FROM (
        SELECT * , ROW_NUMBER() OVER(partition by email order by id) AS rnk
        FROM PERSON
    )t
    WHERE rnk > 1
)
