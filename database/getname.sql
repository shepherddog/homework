delimiter $$

CREATE DEFINER=`root`@`localhost` FUNCTION `getname`() RETURNS char(5) CHARSET latin1
BEGIN
    declare counter int unsigned default 0;
    declare result char(5) default '';
    set counter=floor(rand()*10);
    if counter = 0 then  
        set result = 'Mike';  
    elseif counter = 1 then  
        set result = 'Bob';  
    elseif counter = 2 then  
        set result = 'Jack';  
    elseif counter = 3 then  
        set result = 'Alice'; 
    elseif counter = 4 then  
        set result = 'Cathy';  
    elseif counter = 5 then  
        set result = 'Ann';  
    elseif counter = 6 then  
        set result = 'Betty'; 
    elseif counter = 7 then  
        set result = 'Cindy';  
    elseif counter = 8 then  
        set result = 'Mary';  
    else  
        set result = 'Jane';  
    end if;
    return result;  
END$$

