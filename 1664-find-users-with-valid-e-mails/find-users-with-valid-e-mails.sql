# Write your MySQL query statement below
-- SELECT *
-- FROM Users
-- WHERE mail REGEXP '(?i)^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$';


-- //MySQL REGEXP requires double backslash (\\) before . to match a literal dot.Fix: Add (?i) at the start of regex to make it case-insensitive.


-- SELECT *
-- FROM Users
-- WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$' COLLATE utf8mb4_general_ci;

-- SELECT *
-- FROM Users
-- WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_\.\-]*@leetcode(\\?com)?\\.com$';

# Write your MySQL query statement below
SELECT user_id, name, mail
FROM users
WHERE REGEXP_like(mail, '^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$','c');
