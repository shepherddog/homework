delimiter $$

CREATE DEFINER=`root`@`localhost` FUNCTION `ran_string`() RETURNS char(5) CHARSET latin1
BEGIN
    declare counter int unsigned default 0;
    declare const_char char(5) default 'abcde';
    declare result char(5) default '';
    while counter<5 do
        set result=concat(result,substr(const_char,ceil(rand()*4),1));
        set counter=counter+1;
    end  while;
    return result;  
END$$

