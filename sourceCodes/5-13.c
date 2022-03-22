bool IsWordChar( char c )
{
	if ( c>='a'&& c<='z'
	  || c>='A'&& c<='Z'
	  || c>='0'&& c<='9'
      || c == '_' )
		return true;
	else 
		return false;
}
