-- # Write your MySQL query statement below
-- SELECT s.machine_id ,
--     ROUND(AVG(e.timestamp-s.timestamp), 3) as processing_time
--     from activity s
--     Join activity e
--     on s.machine_id = e.machine_id
--     and s.process_id = e.process_id
--     and s.activity_type='start'
--     and e.activity_type='end'
--     group by machine_id;

# Write your MySQL query statement below
SELECT 
    machine_id,
    ROUND(AVG(end_time - start_time), 3) AS processing_time
FROM (
    SELECT 
        machine_id,
        process_id,
        MAX(CASE WHEN activity_type = 'end' THEN timestamp END) AS end_time,
        MIN(CASE WHEN activity_type = 'start' THEN timestamp END) AS start_time
    FROM Activity
    GROUP BY machine_id, process_id
) AS temp
GROUP BY machine_id;

