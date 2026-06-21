# Write your MySQL query statement below

-- Merge of 2 questions 

(SELECT u.name AS results
FROM Users u 
JOIN 
MovieRating m 
ON u.user_id = m.user_id 
GROUP BY u.user_id , u.name
ORDER BY COUNT(*) DESC , u.name ASC
LIMIT 1)

UNION ALL

(SELECT m.title AS results
FROM Movies m
JOIN 
MovieRating mr
on m.movie_id = mr.movie_id 
WHERE mr.created_at BETWEEN 
        '2020-02-01' 
        AND 
        '2020-02-29'
GROUP BY m.movie_id, m.title 
ORDER BY AVG(rating) DESC , m.title ASC
LIMIT 1)
