```
<extension name="call_forwarding_activativation">
 <condition field="destination_number" expression="^\*72$">
    <action application="play_and_get_digits" data="3 12 1 14000 # tone_stream://%(10000,0,350,440) silence_stream://250 cfwd_num \d+"/>      
    <action application="hash" data="insert/${domain_name}-call_forward/${caller_id_number}/${cfwd_num}"/>
    <action application="playback" data="tone_stream://${bong-ring}"/>
    <action application="hangup"/>
 </condition>
</extension>
```
``` 
<extension name="call_forwarding_deactivation">
 <condition field="destination_number" expression="^\*73$">        
    <action application="hash" data="delete/${domain_name}-call_forward/${caller_id_number}/${destination_number}"/>
    <action application="playback" data="tone_stream://${bong-ring}"/>
    <action application="hangup"/>
 </condition>
</extension>
```
 
``` 
<extension name="call_forwarding_number" continue="true">
 <condition>
    <action application="set" data="call_forwarding_number=${hash(select/${domain_name}-call_forward/${destination_number})}"/>
 </condition>
</extension>
```
