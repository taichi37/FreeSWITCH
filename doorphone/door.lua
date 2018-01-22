r = io.open( "/dev/ttyUSB0", "r" );
ch1 = r:read();
r:flush();

function sleep( s )
    os.execute( "sleep " .. s );
end

while 1 do
    local ch = r:read(); 
    r:flush();
    
    if ch == "1000" then
        os.execute( "linphonecsh dial 1016" );
    end

    if ch == "1018" then
        os.execute( "linphonecsh dial 1002" );
    end

    sleep( 0.1 );
end
